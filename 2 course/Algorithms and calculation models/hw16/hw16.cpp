#include <iostream>
#include <string>
#include <utility>

class long_dec
{
private:
	struct Node
	{
		Node* next;
		Node* prev;
		short value;
	};
	Node* tail;
	Node* head;
	std::pair<size_t, bool> __add__digits__carry(char value, char value1, bool carry)
	{
		size_t sum = (value - 0x30 + value1 - 0x30) + carry;
		if (sum >= 10)
			return std::make_pair(sum % 10, true);
		else
			return std::make_pair(sum, false);
	}
	std::pair<size_t, bool> __sub__digits__carry(char value, char value1, bool carry)
	{
		int sum = ((value - 0x30) - carry - (value1 - 0x30));
		if (sum < 0)
			return std::make_pair(10 + sum, true);
		else
			return std::make_pair(sum, false);
	}
public:

	long_dec()
	{
		tail = NULL;
		head = NULL;
	}
	long_dec(std::string _dec)
	{
		for (size_t i = 0; i < _dec.size(); ++i)
			this->add(this->head, _dec[i]);
	}
	void from_string(std::string _dec)
	{
		for (size_t i = 0; i < _dec.size(); ++i)
			this->add(this->head, _dec[i]);
	}
	void add(Node* _Node, char value)
	{
		if (_Node == NULL)
		{
			head = _Node = new Node;
			if (value == '-')
				_Node->value = value;
			else _Node->value = value - 0x30;
			tail = _Node;
			_Node->next = NULL;
			_Node->prev = NULL;
		}
		else if (_Node == tail)
		{
			_Node->next = new Node;
			tail = _Node->next;
			_Node->next->value = value - 0x30;
			_Node->next->prev = _Node;
			_Node->next->next = NULL;
		}
		else
			add(_Node->next, value);
	}
	Node* get_head() const
	{
		return head;
	}
	size_t lenght() const
	{
		Node* _Node = head;
		size_t lenght = 0;
		while (_Node != NULL)
		{
			_Node = _Node->next;
			++lenght;
		}
		return lenght;
	}
	void print(Node* _Node)
	{
		if (_Node == NULL)
			return;
		std::cout << _Node->value;
		print(_Node->next);
	}
	std::string to_string()
	{
		Node* _Node = head;
		std::string str;
		while (_Node != NULL)
		{
			if (_Node != NULL)
			{
				if (_Node->value == '-')
					str.push_back('-');
				else str.push_back(_Node->value + 0x30);
			}

			_Node = _Node->next;
		}
		return str;
	}
	friend std::istream& operator>>(std::istream& is, long_dec& ld)
	{
		std::string buffer;
		is >> buffer;
		for (size_t i = 0; i < buffer.size(); ++i)
			ld.add(ld.head, buffer[i]);
		return is;
	}
	long_dec operator+(long_dec& ld)
	{
		std::string bigger = lenght() >= ld.lenght() ? this->to_string() : ld.to_string();
		std::string lower = lenght() < ld.lenght() ? this->to_string() : ld.to_string();
		size_t dif = bigger.size() - lower.size();
		for (size_t i = 0; i < dif; ++i)
			lower.insert(lower.begin(), '0');

		std::pair<size_t, bool> carry = std::pair<size_t, bool>(0, 0);
		std::string res_str;

		for (int i = bigger.size() - 1; i >= 0; --i)
		{
			carry = __add__digits__carry(bigger[i], lower[i], carry.second);
			res_str.insert(res_str.begin(), carry.first + 0x30);
		}
		if (carry.second == true)
			res_str.insert(res_str.begin(), '1');
		long_dec res;
		res.from_string(res_str);
		return res;
	}
	long_dec operator-(long_dec& ld)
	{
		std::string bigger = this->to_string();
		std::string lower = ld.to_string();

		bool is_minus = false;

		int dif = fabs(bigger.size() - lower.size());
		int bs = bigger.size() > lower.size() ? bigger.size() : lower.size();

		if (dif == 0 || bigger.size() < lower.size())
		{
			for (int i = 0; i < bs; ++i)
			{
				if ((bigger[i] - 0x30) < (lower[i] - 0x30))
					is_minus = 1;
			}
		}

		if (is_minus)
		{
			std::string tmp = bigger;
			bigger = lower;
			lower = tmp;
		}
		if (bigger.size() > lower.size())
		{
			for (size_t i = 0; i < dif; ++i)
				lower.insert(lower.begin(), '0');
		}
		else if (bigger.size() < lower.size())
		{
			for (size_t i = 0; i < dif; ++i)
				bigger.insert(bigger.begin(), '0');
		}
		std::pair<size_t, bool> carry = std::pair<size_t, bool>(0, 0);
		std::string res_str;


		for (int i = bigger.size() - 1; i >= 0; --i)
		{
			carry = __sub__digits__carry(bigger[i], lower[i], carry.second);
			res_str.insert(res_str.begin(), carry.first + 0x30);
		}
		if (res_str[0] == '0')
			res_str.erase(res_str.begin(), res_str.begin() + 1);
		if (is_minus)
			res_str.insert(res_str.begin(), '-');
		long_dec res;
		res.from_string(res_str);
		return res;
	}
};

int main()
{
	std::cout << "\tOP - \n";
	long_dec dec;
	long_dec dec1;
	std::cout << "Enter first big value\n>";
	std::cin >> dec;
	std::cout << "Enter secound big value\n>";
	std::cin >> dec1;
	long_dec dec2 = dec - dec1;
	std::cout << dec.to_string() << " - " << dec1.to_string() << " = " << dec2.to_string() << "\n";
}
