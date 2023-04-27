#ifndef OP_MAKE_SHARED_H
#define OP_MAKE_SHARED_H

#include <memory>
#include <stdexcept>
#include "op_value.h"
#include "sqDatabase.h"

// op_make_shared: Restore a persistent op_lite object from a database as a std::shared_ptr
//
// Note1: This is useful mostly for read-only situations.
// Note2: The object is not entered into the database cache,
//        changes to the object will be lost unless explicitly saved
// Note3: The in-core lifetime of the object is managed by the shared_ptr in the usual way
// Note4: When multiple threads are reading objects from the same data type,
//        op_make_shared is safe to use, while op_ptr does NOT support multiple threads.

template <typename T>
std::shared_ptr<T> op_make_shared(op_database* db, IDint64 id)
{
   if(db == nullptr) throw std::runtime_error("op_make_shared: cannot restore object from NULL database");

   // TODO: when type factory is in database, make proper
   // polymorphic type here. For now we just create non-polymorphic type
   auto obj = std::make_shared<T>();
   db->restore_persistent(id,obj.get());
   return obj;
}


template <typename T>
inline std::shared_ptr<T> op_make_shared(const op_pid& id)
{
   return op_make_shared(id.table()->db(),id.id());
}


#endif // OP_MAKE_SHARED_H
