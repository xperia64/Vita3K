#include <ngs/definitions/player.h>
#include <ngs/modules/equalizer.h>
#include <ngs/modules/player.h>

namespace ngs::player {
void VoiceDefinition::new_modules(std::vector<std::unique_ptr<ngs::Module>> &mods) {
    mods.push_back(std::make_unique<Module>());
    mods.push_back(nullptr); // Not yet known
    mods.push_back(nullptr); // Seems to be mixer?
    mods.push_back(std::make_unique<ngs::equalizer::Module>());

    for (int i = 0; i < 6; i++) {
        mods.push_back(nullptr);
    }
}

std::size_t VoiceDefinition::get_total_buffer_parameter_size() const {
    return sizeof(Parameters) + default_parameter_size * 9;
}
} // namespace ngs::player
