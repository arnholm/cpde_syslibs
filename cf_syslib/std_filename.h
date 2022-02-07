#ifndef STD_FILENAME_H
#define STD_FILENAME_H

#include "cf_syslib_config.h"

// std_filename is intended to mimic some of the most common features in
// wxWidgets::wxFileName, but using std::string and boost for implementation
// The function names use wxWidgets CamelCase and are supposed to have the same meaning as in wxFileName

#include <string>
#include <vector>
#include <boost/filesystem.hpp>

class CF_SYSLIB_PUBLIC std_filename {
public:
   std_filename();
   std_filename(const std::string& file_path);
   virtual ~std_filename();

   // Returns true if either a file or a directory or something else with this name exists in the file system.
   static bool Exists(const std::string& file_path);

   // Returns true if the file with name file exists.
   static bool FileExists(const std::string& file_path);

   // Returns the full name (including extension but excluding directories).
   std::string GetFullName() const;

   // Returns the file name extension.
   std::string GetExt() const;

   // Returns the name part of the filename (without extension).
   std::string GetName() const;

   // Returns the path part of the filename (without the name or extension).
   std::string GetPath() const;

   // Returns the full path with name and extension.
   std::string GetFullPath() const;

   // return the directories as a vector of strings
   std::vector<std::string> GetDirs() const;

   // returns true if this file exists
   bool Exists() const     { return Exists(m_path.string()); }
   bool FileExists() const { return FileExists(m_path.string()); }

   // The full name is the file name and extension (but without the path).
   void SetFullName(const std::string& fullname);

   // Sets the extension of the file name.
   void SetExt(const std::string& ext);

   // Sets the name part (without extension).
   void SetName(const std::string& name);

   // Sets the path.
   void SetPath(const std::string& path);

   // normalise the Path
   bool Normalize();

   // Removes last directory component from the path.
   void RemoveLastDir();

   // EXTENSIONS (not in wxFileName)
   static void RemoveFile(const std::string& path);
   void RemoveFile();

   // returns the current directory
   static std::string get_current_directory();

   // sets the current directory
   static void  set_current_directory(const std::string& dir_path);

   // create directory
   static void create_directory(const std::string& dir_path, bool throw_if_exists = true);

private:
   boost::filesystem::path m_path;
};

#endif // std_filename_H
