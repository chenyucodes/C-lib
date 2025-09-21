#include "StringUitls.h"

using namespace tmmp::base;

bool StringUitls::StartWith(const string& s,const string& sub){
	if (s.empty())	return false;
	if (sub.empty())	return true;
	auto len = s.size();
	auto slen = s.size();
	if (len < slen)	return false;
	return s.compare(0, slen, sub)==0;
}

bool StringUitls::EndWith(const string& s, const string& sub) {
	if (s.empty())	return false;
	if (sub.empty())	return true;
	auto len = s.size();
	auto slen = s.size();
	if (len < slen)	return false;
	return s.compare(len-slen, slen, sub) == 0;

}

std::string StringUitls::FilePath(const std::string& path) {

	//从后往前查找最后一次出现的 '/' 或 '\\' 出现的字符的位置
	auto pos = path.find_last_of("/\\");		//没找到返回 std::string::npos
	if (pos != std::string::npos) {
		return path.substr(0, pos);
	}
	else {
		return "/";
	}
}
/***********************************************************
*	FilePath	("C:\\Users\\test\\file.txt");
*	// 返回		"C:\\Users\\test"
************************************************************/

//------------------------------------------------------------------//

std::string StringUitls::FilenamePath(const std::string& path) {
	auto pos = path.find_last_of("/\\");
	if (pos != std::string::npos) {
		if (pos + 1 < path.size()) {
			return path.substr(pos + 1);
		}
	}
	return path;
}
/*************************************************************
*	FilenamePath	("C:\\Users\\test\\file.txt");
*	// 返回			"file.txt"
*************************************************************/

//------------------------------------------------------------------//

std::string StringUitls::FileName(const std::string& path) {
	string file_name = FilenamePath(path);
	auto pos = file_name.find_last_of(".");
	if (pos != std::string::npos) {
		if (pos != 0) {
			return file_name.substr(0,pos);
		}
	}
	return file_name;
}

//------------------------------------------------------------------//

std::string StringUitls::Extension(const std::string& path) {
	string file_name = FilenamePath(path);
	auto pos = file_name.find_last_of(".");
	if (pos != std::string::npos) {
		if (pos != 0 && pos+1 <file_name.size()) {
			return file_name.substr(pos+1);
		}
	}
	return std::string();
}

//------------------------------------------------------------------//

std::vector<std::string> StringUitls::Splitstring(const string& s, const string& delimiter) {
	if (delimiter.empty()) {
		return std::vector<std::string>{};
	}
	std::vector<std::string> result;
	size_t last = 0;
	size_t next = 0;
	while ((next = s.find(delimiter,last))!=std::string::npos) {
		if (next > last) {
			result.emplace_back(s.substr(last,next-last));
		}
		last = next + delimiter.size();
	}
	if (last < s.size()) {
		result.emplace_back(s.substr(last));
	}
	return result;
}