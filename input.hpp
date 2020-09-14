#ifndef INPUT_BRACES_H
#define INPUT_BRACES_H

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>  // used for transform only
#include "optional_ptr.hpp"
#include "types.hpp"


namespace input_braces{

  class InputFile{	
  public:
    InputFile(): opened_(false) {}
    InputFile(std::string fname): filename_(fname), opened_(false) {}
	void open();
	void close();
	std::string const&
	  filename() const { return filename_; }
	std::ifstream&
	  file() { return file_; }
	std::ifstream const&
	  file() const { return file_; }
    bool opened() const { return opened_; }
	
  private:
	std::string filename_;
    std::ifstream file_;
    bool opened_;
  };

  std::ostream& operator<<(std::ostream &s, InputFile const& a);


  class InputGroup{
  public:
    InputGroup() {}
    InputGroup(std::string filename, std::string groupname, const char* c = 0);
    InputGroup(InputFile& inf, std::string name, const char* c = 0);
    InputGroup(InputGroup& par, std::string name, const char* c = 0);
    ~InputGroup();

    const std::string&
	  name() const { return name_; }
	std::ifstream&
	  file() const { return infile->file(); }

    // These versions return their value
    int getInt(std::string s, int default_);
    Real getReal(std::string s, Real default_);
    std::string getString(std::string s, std::string default_);
    bool getYesNo(std::string s, bool default_);

    int getInt(std::string s);
    Real getReal(std::string s);
    std::string getString(std::string s);
    bool getYesNo(std::string s);

    // The following go to s, and read into i, r, t, or yes
    int GetInt(std::string s, int& i, bool hasdf = false, int df = 0);
    int GetLong(std::string s, long& i, bool hasdf = false, long df = 0);
    int GetReal(std::string s, Real& r, bool hasdf = false, Real df = 0);	
    int GetString(std::string s, std::string& t, bool hasdf = false, std::string df = "");
    int GetYesNo(std::string s, int& yes, bool hasdf = false, int df = 0);  // yes / no
    int GetYesNo(std::string s, bool& yes, bool hasdf = false, bool df = 0);  // yes / no

    // The following are mandatory versions; if they doesn't get it, we quit
    void GetIntM(std::string s, int& i);	
    void GetLongM(std::string s, long& i);	
    void GetRealM(std::string s, Real& r);
    void GetStringM(std::string s, std::string& t);
    void GetYesNoM(std::string s, int& yes);

    void SkipLine();

    int GotoGroup();  // Goes to group, then eats "{" + whitespace
    int GotoToken(std::string s);  // Goes to Token, then eats "=" + whitespace

  private:
    optional_ptr<InputFile,std::shared_ptr<InputFile>> infile;
    InputGroup* parent;
    std::string name_;
    bool quiet;

  };

} //* namespace input_braces


#endif //* INPUT_BRACES_H
