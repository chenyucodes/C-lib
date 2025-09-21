#pragma once

#include <string>
#include <vector>

namespace tmmp {

	namespace base {
		using std::string;

		class StringUitls {
		public:
			/*  �����ַ���ǰ��׺  */
			static bool StartWith(const string &s,const string &sub);		//ǰ׺ƥ��
			static bool EndWith(const string &s,const string &sub);			//��׺ƥ��
			/*  �ļ�������  */
			static std::string FilePath(const std::string &path);			//��ȡ�ļ�·��
			static std::string FilenamePath(const std::string &path);		//��ȡ�ļ�ȫ��
			static std::string FileName(const std::string& path);			//��ȡ�ļ���
			static std::string Extension(const std::string& path);			//��ȡ�ļ���׺��
			/*  �ַ����ָ�  */
			static std::vector<std::string> Splitstring(const string& s, const string& delimiter);

		};

	}


}



