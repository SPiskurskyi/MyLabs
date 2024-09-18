#include <iostream>
#include <iterator>
#include <list>
#include <future>
#include <stack>
#include <thread>
//#include <exception>
// #include <mutex>
// #include <memory>
// #include <chrono>
#include <vector>
#include <algorithm>

#define DATA_TYPE unsigned long long int
#define INPUT_DATA { 545, 546, 541, 541, 537, 540, 541, 536, 536, 532, 539, 531, 536, 537, 532, 534, 526, 531, 532, 527 }

template<typename F, typename A>
std::future<typename std::result_of<F(A&&)>::type>
spawn_task(F&& f, A&& a){
	//typedef std::result_of<F(A&&)>::type result_type; // C++14
	typedef std::result_of<F(A&&)> result_type;
	std::packaged_task<result_type(A&&)> task(std::move(f));
	std::future<result_type> res(task.get_future());
	std::thread t(std::move(task), std::move(a));
	t.detach();
	return res;
}

template < typename T >
std::list < T > sequential_quick_sort(std::list<T> input){
	if (input.empty()){
		return input;
	}
	std::list<T> result;
	result.splice(result.begin(), input, input.begin()); // (1)

	T const& pivot = *result.begin(); // (2)
	auto divide_point = std::partition(input.begin(), input.end(), [&](T const& t){return t < pivot; }); //(3)

	std::list<T> lower_part;
	lower_part.splice(lower_part.end(), input, input.begin(), divide_point); // (4)

	auto new_lower(sequential_quick_sort(std::move(lower_part))); // (5)
	auto new_higher(sequential_quick_sort(std::move(input))); // (6)

	result.splice(result.end(), new_higher); // (7)
	result.splice(result.begin(), new_lower); // (8)

	return result;
}


template < typename T >
std::list < T > parallel_quick_sort(std::list<T> input){
	if (input.empty()){
		return input;
	}
	std::list<T> result;
	result.splice(result.begin(), input, input.begin());

	T const& pivot = *result.begin();
	auto divide_point = std::partition(input.begin(), input.end(), [&](T const& t){return t < pivot; });

	std::list<T> lower_part;
	lower_part.splice(lower_part.end(), input, input.begin(), divide_point);

	std::future<std::list<T> > new_lower(std::async(&parallel_quick_sort<T>, std::move(lower_part))); // (1)
	auto new_higher(parallel_quick_sort(std::move(input)));  // (2)

	result.splice(result.end(), new_higher); // (3)
	result.splice(result.begin(), new_lower.get()); // (4)

	return result;
}

int main()
{
	std::list<DATA_TYPE> input(INPUT_DATA);
	std::list<DATA_TYPE> output = sequential_quick_sort(input);

	std::cout << "input:" << std::endl;
	std::copy(input.begin(), input.end(), std::ostream_iterator<DATA_TYPE>(std::cout, ", "));
	std::cout << std::endl << std::endl;

	std::cout << "output:" << std::endl;
	std::copy(output.begin(), output.end(), std::ostream_iterator<DATA_TYPE>(std::cout, ", "));
	std::cout << std::endl << std::endl;

	std::cout << "Press Enter to continue . . .";
	std::cin.get();

	return 0;
}
