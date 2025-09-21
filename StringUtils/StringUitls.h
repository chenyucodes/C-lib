#pragma once

#include <string>
#include <vector>

namespace tmmp {

	namespace base {
		using std::string;

		class StringUitls {
		public:
			/*  查找字符串前后缀  */
			static bool StartWith(const string &s,const string &sub);		//前缀匹配
			static bool EndWith(const string &s,const string &sub);			//后缀匹配
			/*  文件名操作  */
			static std::string FilePath(const std::string &path);			//获取文件路径
			static std::string FilenamePath(const std::string &path);		//获取文件全名
			static std::string FileName(const std::string& path);			//获取文件名
			static std::string Extension(const std::string& path);			//获取文件后缀名
			/*  字符串分隔  */
			static std::vector<std::string> Splitstring(const string& s, const string& delimiter);

		};

	}


}



