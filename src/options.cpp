#include <boost/program_options/options_description.hpp>

namespace utils {
class Lines
{
};
/* support of the boost::options */
void validate(boost::any &v, const std::vector<std::string> &values, Lines *, int);
} // \utils

class Options
{
public:
    Options(int, char **)
    {
        using namespace boost::program_options;

        options_description od("options");
        od.add_options()
                ("lines", value<utils::Lines>())
                ("int", value<int>()->default_value(0))
        ;
    }
};

int main(int argc, char **argv)
{
    Options options(argc, argv);
}
