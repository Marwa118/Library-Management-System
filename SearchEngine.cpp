#include "SearchEngine.h"

std::vector<Resource*> SearchEngine::search(const std::vector<Resource*>& resources,
                                            const std::string& keyword) {
    std::vector<Resource*> results;
    for (auto* res : resources) {
        if (res->getTitle().find(keyword) != std::string::npos ||
            res->getAuthor().find(keyword) != std::string::npos) {
            results.push_back(res);
        }
    }
    return results;
}
