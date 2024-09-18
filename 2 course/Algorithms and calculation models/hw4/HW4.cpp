#include <iostream>
#include <string>
#include <boost/spirit/include/qi.hpp>
using std::string;
namespace qi = boost::spirit::qi;

template <typename Iterator>
struct calculator_simple : qi::grammar<Iterator> {
    calculator_simple() : calculator_simple::base_type(expression) {
        expression = term_a >> *('+' >> term_a);
        term_a = term_m >> *('/' >> term_m | '%' >> term_m);
        term_m =
            qi::uint_
            | '(' >> expression >> ')'
            | '+' >> term_m
            | '-' >> term_m;
    }
    qi::rule<Iterator> expression, term_a, term_m;
};


int main() {
    std::cout << "Welcome to the expression parser!\n\n";
    std::cout << "Type an expression or [q or Q] to quit\n\n";
    calculator_simple<string::iterator> calc;
    string expression;
    while (true) {
        std::getline(std::cin, expression);
        if (expression == "q" || expression == "Q") break;
        string::iterator begin = expression.begin(), end = expression.end();
        bool success = qi::parse(begin, end, calc);
        std::cout << "---------------------\n";
        if (success && begin == end)
            std::cout << "Parsing succeeded\n";
        else
            std::cout << "Parsing failed\nstopped at: \""
            << string(begin, end) << "\"\n";
        std::cout << "---------------------\n";
    }
}
