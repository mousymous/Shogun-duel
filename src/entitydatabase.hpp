#include "libraries.hpp"

#ifndef ENTITY_DATABASE_HPP
#define ENTITY_DATABASE_HPP

// Class representing the database of entities.
// It allows you to store and manage all entities (objects in the game world) in a collection.

class Entity_Database {

private:
     // Vector to store the entities. Each entity is an object of type Entity.
    std::vector<Entity> entity_list;

public:
    Entity_Database() = default;

    // Adds a new entity to the entity database.
    // This method takes a reference to an entity and adds it to the entity list.
    void add_entity(const Entity& entity) {
        entity_list.push_back(entity);
    }

    // Retrieves an entity from the database by its ID (index).
    // It returns a reference to the entity at the specified index.
    Entity& get_entity(size_t ID) {
        return entity_list[ID];
    }
};

#endif