#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <stack>

class tag
{
std::string name;
std::map<std::string, std::string> attributes;
std::map<std::string, tag *> subtags;

public:
    explicit tag(std::string name) : name(name) {}

    void cleanup()
    {
        for (std::map<std::string, tag *>::iterator map_it = subtags.begin(); map_it != subtags.end(); ++map_it)
        {
            map_it->second->cleanup();
            delete map_it->second;
        }
    }

    void add_attribute(std::string name, std::string value)
    {
        attributes.insert(std::pair<std::string, std::string>(name, value));
    }

    void add_tag(std::string name, tag *tag_ob)
    {
        subtags.insert(std::pair<std::string, tag *>(name, tag_ob));
    }

    tag *get_tag(std::string name)
    {
        std::map<std::string, tag *>::iterator map_it = subtags.find(name);

        if (map_it != subtags.end())
            return map_it->second;
        else
            return nullptr;
    }

    std::string get_attribute(std::string name)
    {
        std::map<std::string, std::string>::iterator map_it = attributes.find(name);

        if (map_it != attributes.end())
            return map_it->second;
        else
            return "Not Found!";
    }

    std::string get_name()
    {
        return name;
    }
};

/**
 * A function that splits a std::string using delim as the delimiter between the
 * substrings.
 * @param   str     the std::string to be split into substrings
 * @param   delim   the char that will be used as a delimiter between the
 * substrings
 * @return          a std::vector<std::string> containing the substrings
 */
std::vector<std::string> split(std::string &str, char delim = ' ')
{
    std::vector<std::string> tokens;

    std::string::iterator start = str.begin();
    std::string::iterator finish = str.end();

    if (*start == '<')     // it's in tag format
    {
        ++start;    // skip '<'
        --finish;   // don't include '>'

        if (*start == '/')   // it's a closing tag
        {
            return tokens;  // return an empty vector
        }
    }

    std::string::iterator it = start;

    while (it != finish)
    {
        ++it;
        if (*it == delim)
        {
            tokens.push_back(std::string(start, it));   // a token was found, push it
            ++it;
            start = it;
        }
    }
    tokens.push_back(std::string(start, it));   // push the last token

    return tokens;
}

int main()
{
    std::string line;
    std::getline(std::cin, line);

    int num_lines, num_queries;
    std::stringstream ss(line);
    ss >> num_lines >> num_queries;

    std::stack<tag *> tags_stack;
    tags_stack.push(new tag("container"));     // the container tag

    // read all tags
    for (int i = 0; i < num_lines; ++i)
    {
        std::getline(std::cin, line);
        std::vector<std::string> tokens = split(line);

        if (!tokens.empty())    // it's an opening tag
        {
            tag *new_tag = new tag(tokens[0]);  // create a new tag
            tags_stack.top()->add_tag(tokens[0], new_tag);  // add the new tag to the subtags of the top tag
            tags_stack.push(new_tag);    // push the new tag in the heap

            if (tokens.size() > 1)  // it has attributes, so grub them
            {
                for (std::vector<std::string>::iterator it = tokens.begin() + 1; it != tokens.end(); it+=3)
                {
                    std::string value = *(it + 2);  // don't include the ""s
                    tags_stack.top()->add_attribute(*it, std::string(value, 1, value.size() - 2));
                }
            }
        }
        else    // it's a closing tag
        {
            tags_stack.pop();
        }
    }

    // read and answer all queries
    for (int i = 0; i < num_queries; ++i)
    {
        std::getline(std::cin, line);
        std::vector<std::string> tokens = split(line, '.');
        std::vector<std::string> last_token = split(tokens.back(), '~');

        tokens[tokens.size() - 1] = last_token[0];  // remove the attribute name from the last token

        tag *ptag = tags_stack.top();

        for (std::vector<std::string>::iterator it = tokens.begin(); it != tokens.end(); ++it)
        {
            ptag = ptag->get_tag(*it);  // move to next subtag if it exists
            if (ptag == nullptr)
                break;
        }

        if (ptag != nullptr)    // if the leaf tag exists
        {
            // print the value of the attribute if available, else "Not found!"
            std::cout << ptag->get_attribute(last_token[1]) << '\n';
        }
        else
        {
            std::cout << "Not Found!\n";
        }
    }

    tags_stack.top()->cleanup();
    delete tags_stack.top();

    return 0;
}
