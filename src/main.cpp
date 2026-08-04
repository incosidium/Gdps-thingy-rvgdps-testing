#include <Geode/Geode.hpp>
#include <Geode/utils/web.hpp>
#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

void fetchRVGDPSList() {
    // Exact raw URL to your RVGDPS demonlist array file
    std::string listUrl = "https://raw.githubusercontent.com/Incosidium/RVGDPS-Demonlist/main/data/_list.json";

    web::WebRequest req;
    req.get(listUrl).listen([](auto result) {
        if (result && result->ok()) {
            auto jsonResult = result->json();
            if (jsonResult) {
                auto listArray = jsonResult.value();
                
                // Iterates through the top level names on your list
                if (listArray.is_array()) {
                    for (auto const& item : listArray.as_array()) {
                        std::string levelFileName = item.as_string();
                        log::info("Found Demon: {}", levelFileName);
                    }
                }
            }
        } else {
            log::error("Failed to fetch RVGDPS list data.");
        }
    });
}

class $modify(MyMenuLayer, MenuLayer) {
    bool init() {
        if (!MenuLayer::init()) return false;

        fetchRVGDPSList();

        return true;
    }
};
