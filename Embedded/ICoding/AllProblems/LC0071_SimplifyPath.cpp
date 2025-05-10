/*
71. Simplify Path
Solved
Medium
Topics
Companies
You are given an absolute path for a Unix-style file system, which always begins with a slash '/'. Your task is to transform this absolute path into its simplified canonical path.

The rules of a Unix-style file system are as follows:

A single period '.' represents the current directory.
A double period '..' represents the previous/parent directory.
Multiple consecutive slashes such as '//' and '///' are treated as a single slash '/'.
Any sequence of periods that does not match the rules above should be treated as a valid directory or file name. For example, '...' and '....' are valid directory or file names.
The simplified canonical path should follow these rules:

The path must start with a single slash '/'.
Directories within the path must be separated by exactly one slash '/'.
The path must not end with a slash '/', unless it is the root directory.
The path must not have any single or double periods ('.' and '..') used to denote current or parent directories.
Return the simplified canonical path.

 

Example 1:

Input: path = "/home/"

Output: "/home"

Explanation:

The trailing slash should be removed.

Example 2:

Input: path = "/home//foo/"

Output: "/home/foo"

Explanation:

Multiple consecutive slashes are replaced by a single one.

Example 3:

Input: path = "/home/user/Documents/../Pictures"

Output: "/home/user/Pictures"

Explanation:

A double period ".." refers to the directory up a level (the parent directory).

Example 4:

Input: path = "/../"

Output: "/"

Explanation:

Going one level up from the root directory is not possible.

Example 5:

Input: path = "/.../a/../b/c/../d/./"

Output: "/.../b/d"

Explanation:

"..." is a valid name for a directory in this problem.

 

Constraints:

1 <= path.length <= 3000
path consists of English letters, digits, period '.', slash '/' or '_'.
path is a valid absolute Unix path.
*/

/*
Stack: only store folder names, pass on /
., if do nothing
.., pop
else push to stack
*/

class Solution {
    private:
        string path="";
        stack<string> stkPath;
    public:
        string simplifyPath(string path) {
            int len1=path.length(),i=0,dotcnt=0,namecnt=0;
            bool print=false;
            string name;
            if(len1==0) return path;
            if(len1==1)
            {
                if(path[0]=='/') return "/";
                else if(path[0]=='.') return "";
                else    return path;
            }
            while(i<len1)
            {
                name="";namecnt=0;dotcnt=0;
                while(i<len1 && path[i]=='/') i++;
                if(i==len1) break;
                while(i<len1 && path[i]!='/')
                {
                    if(path[i]=='.')    dotcnt++;
                    name+=path[i];namecnt++;
                    if(print)   cout<<"path[i]"<<path[i]<<",dots:"<<dotcnt<<"name:"<<name<<endl;
                    i++;
                }
                if(dotcnt==2 && namecnt==2)
                {
                    if(!stkPath.empty())    stkPath.pop();
                }
                else if(dotcnt==1 && namecnt==1)  {}
                else
                {
                    stkPath.push(name);
                    if(print)   cout<<"name-"<<name<<endl;
                }
                i++;
            }
            //make valid path
            if(stkPath.empty()) return "/";
            path=stkPath.top();
            stkPath.pop();
            while(!stkPath.empty())
            {
                path=stkPath.top()+"/"+path;
                stkPath.pop();
            }
            path="/"+path;
            return path;
        }
    };

/*
Runtime
3
ms
Beats
58.87%
Analyze Complexity
Memory
11.98
MB
Beats
23.30%
*/