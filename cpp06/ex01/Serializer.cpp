#include "Serializer.hpp"

// Private constructor and destructor implementation
Serializer::Serializer() {}
Serializer::~Serializer() {}
Serializer::Serializer(const Serializer &other) { (void)other; }
Serializer &Serializer::operator=(const Serializer &other) { (void)other; return *this; }

// Serialize a Data pointer to uintptr_t
uintptr_t Serializer::serialize(Data *ptr)
{
    return reinterpret_cast<uintptr_t>(ptr);
}

// Deserialize a uintptr_t back to a Data pointer
Data *Serializer::deserialize(uintptr_t raw)
{
    return reinterpret_cast<Data *>(raw);
}