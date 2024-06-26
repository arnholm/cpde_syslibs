#ifndef CF_YAML_MAP_H
#define CF_YAML_MAP_H

#include "cf_yaml_value.h"
#include <unordered_map>
#include <vector>

// map class for yml values parsed with cf_yaml_handler or created programmatically
class CF_YAML_PUBLIC cf_yaml_map : public cf_yaml_value {
public:
   cf_yaml_map();
   virtual ~cf_yaml_map();

   // insert keyed entry into map
   void insert(const std::string& key, cf_yaml_value_ptr value);

   // retrieve value by string key
   cf_yaml_value_ptr get(const std::string& key, bool throw_exception = true);

public:
   virtual cf_yaml_ostream& to_yaml(cf_yaml_ostream& out) const;
   void debug_print(size_t indent, std::ostream& out);

protected:
   size_t assign(cf_yaml_value_ptr ptr);

private:
   std::vector<std::string>                          m_insert_order;
   std::unordered_map<std::string,cf_yaml_value_ptr> m_map;

   std::vector<cf_yaml_value_ptr>                    m_cache;
};

#endif // CF_YAML_MAP_H
