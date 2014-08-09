#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>
#include <set>

// find all anagrams from a list of words

std::string sortWord(std::string w) {
    std::string sorted = w;
    std::sort(sorted.begin(), sorted.end());
    return sorted;
}

int main() {
    std::multimap<std::string, std::string> ana;
    std::set<std::string> words;

    words.insert("alerting");
    words.insert("altering");
    words.insert("arrest");
    words.insert("aster");
    words.insert("ate");
    words.insert("bares");
    words.insert("baser");
    words.insert("bears");
    words.insert("braes");
    words.insert("drapes");
    words.insert("drawer");
    words.insert("eat");
    words.insert("emits");
    words.insert("eta");
    words.insert("integral");
    words.insert("items");
    words.insert("mites");
    words.insert("parsed");
    words.insert("rarest");
    words.insert("rasped");
    words.insert("raster");
    words.insert("raters");
    words.insert("rates");
    words.insert("redraw");
    words.insert("relating");
    words.insert("reward");
    words.insert("saber");
    words.insert("smite");
    words.insert("spared");
    words.insert("spread");
    words.insert("stare");
    words.insert("starer");
    words.insert("stear");
    words.insert("tae");
    words.insert("tea");
    words.insert("tears");
    words.insert("times");
    words.insert("triangle");
    words.insert("warder");
    words.insert("warred");

    for (std::set<std::string>::iterator it = words.begin(); it != words.end(); ++it) {
        ana.insert(std::make_pair<std::string, std::string>(sortWord(*it), (*it)));
    }

    for (std::multimap<std::string, std::string>::iterator it = ana.begin(); it != ana.end(); ++it) {
        std::cout << (*it).first << " => " << (*it).second << std::endl;
    }

    return 0;
}
