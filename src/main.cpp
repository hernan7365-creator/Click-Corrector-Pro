
#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>
#include <random>
#include <string>

using namespace geode::prelude;

namespace {
    std::mt19937& rng() {
        static std::mt19937 engine{std::random_device{}()};
        return engine;
    }

    int getProtectionChance() {
        auto value = Mod::get()->getSettingValue<std::string>(
            "survivalChance"
        );

        try {
            return std::clamp(std::stoi(value), 0, 100);
        } catch (...) {
            return 100;
        }
    }
}

class $modify(CCP_PlayLayer, PlayLayer) {
    void destroyPlayer(PlayerObject* player, GameObject* object) {
        if (Mod::get()->getSettingValue<bool>("enabled")) {
            std::uniform_int_distribution<int> roll(1, 100);

            if (roll(rng()) <= getProtectionChance()) {
                return;
            }
        }

        PlayLayer::destroyPlayer(player, object);
    }
};
