#include <lfortran/string_utils.h>

namespace LFortran
{


bool startswith(const std::string &s, const std::string &e)
{
    if (s.size() < e.size()) return false;
    return s.substr(0, e.size()) == e;
}

bool endswith(const std::string &s, const std::string &e)
{
    if (s.size() < e.size()) return false;
    return s.substr(s.size()-e.size()) == e;
}

std::vector<std::string> split(const std::string &s)
{
    std::vector<std::string> result;
    std::string split_chars = " \n";
    size_t old_pos = 0;
    size_t new_pos;
    while ((new_pos = s.find_first_of(split_chars, old_pos)) != std::string::npos) {
        result.push_back(s.substr(old_pos, new_pos-old_pos));
        old_pos = new_pos+1;
    }
    result.push_back(s.substr(old_pos));
    return result;
}

std::string join(const std::string j, const std::vector<std::string> &l)
{
    std::string result;
    for (size_t i=0; i<l.size(); i++) {
        result += l[i];
        if (i < l.size()-1) result += j;
    }
    return result;
}

std::vector<std::string> slice(const std::vector<std::string>& v, int start, int end)
{
    int oldlen = v.size();
    int newlen;

    if (end == -1 or end >= oldlen){
        newlen = oldlen-start;
    } else {
        newlen = end-start;
    }

    std::vector<std::string> nv(newlen);

    for (int i=0; i<newlen; i++) {
        nv[i] = v[start+i];
    }
    return nv;
}

} // namespace LFortran
