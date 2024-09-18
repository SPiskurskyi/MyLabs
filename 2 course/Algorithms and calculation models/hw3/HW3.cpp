#include <regex>
#include <iostream>

int main()
{
	std::string text{ "We’re civilised! And we set _forth"
						"To _enlighten others,"
						"To make them see the sun of _truth...."
						"Our blind, simple _brothers!!"
						"We'll show you everything! If but "
						"_Yourselves to us you’ll yield."
						"The _grimmest prisons how to build,"
						"How _shackles forge of _steel,"
						"And how to wear them!... How to pleat"
						"The cruellest _knouts!— Oh yes, we’ll teach"
						"You _everything!If but to us"
						"Your mountains blue you’ll cede,"
						"The last... _because your seasand fields"
						"We have already seized."
	}; // Taras Shevchenko THE CAUCASUS

	std::regex re("\\b_[a-z]{8}\\b");
	std::sregex_iterator next(text.begin(), text.end(), re);
	std::sregex_iterator end;
	while (next != end) {
		std::smatch match = *next;
		std::cout << match.str() << "\n";
		next++;
	}


}
