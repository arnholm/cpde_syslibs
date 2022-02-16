#ifndef CF_YAML_SCALAR_H
#define CF_YAML_SCALAR_H

#include "cf_yaml_value.h"

// scalar class for yml values parsed with cf_yaml_handler
class CF_YAML_PUBLIC cf_yaml_scalar : public cf_yaml_value {
public:
   cf_yaml_scalar(const std::string& value);
   virtual ~cf_yaml_scalar();

   bool is_scalar() const { return true; }
   virtual std::string value() const { return m_value; }

   virtual cf_yaml_ostream& to_yaml(cf_yaml_ostream& out) const;

   void debug_print(size_t indent, std::ostream& out);
private:
   std::string m_value;
};



#endif // CF_YAML_SCALAR_H
