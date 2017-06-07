#include <boost/program_options/value_semantic.hpp> /** validate */

namespace utils {

class Lines;

void validate(boost::any &,
              const std::vector<std::string> &values,
              Lines *, int)
{
    std::vector<std::string> vec;
    boost::any val = vec;
    boost::program_options::validate(val, values, &vec, 0);
}

} // \utils
