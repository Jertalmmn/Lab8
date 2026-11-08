#include "CheeseRepository.h"
#include <stdexcept>


CheeseRepository::CheeseRepository() {
    auto data = DataLoader::LoadFromFile("cheese.txt");
    data_ = std::move(data);
}

int CheeseRepository::GetAvailableQuantity(const std::string& tomatoType) const {
    auto it = data_.find(tomatoType);
    if (it == data_.end()) {
        throw std::invalid_argument("Tipo de queso desconocido: " + tomatoType);
    }
    return std::stoi(it->second[0]);
}

void CheeseRepository::UpdateQuantity(const std::string& tomatoType, int newQuantity) {
    auto it = data_.find(tomatoType);
    if (it == data_.end()) {
        throw std::invalid_argument("Tipo de tomate desconocido: " + tomatoType);
    }
    it->second[0] = std::to_string(newQuantity);
}