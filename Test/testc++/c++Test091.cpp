#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;

struct Student{
    string id;
    string name;
    map<string,double> scores;
    double avgScore;

    void CalAvgScore(map<string,double> scores)
    {
        double score=0;
        for(auto& pair:scores)
        {
            score+=pair.second;
        }
        avgScore=score/scores.size();
    }
};

bool cmpID(Student& s1,Student& s2)
{
    return s1.id<s2.id;
}

int main()
{
    string t;
    vector<Student> students;
    vector<string> courseNames;
    double avgSum = 0;
    //输入并更新学生的信息
    while(getline(cin,t))
    {
        //拆分句子
        string line;
        vector<string> lines;
        int pos ;
        while( (pos = t.find(',')) <t.size())
        {
            line=t.substr(0,pos);
            lines.push_back(line);
            t.erase(0,pos+1);
        }
        lines.push_back(t);

        //更新学生信息
        Student student;
        bool flag = false;
        if(lines.size()==2)
        {
            string id=lines[0];
            string name=lines[1];

            // 检查学生列表中是否已经存在该学生的基本信息
            auto it = find_if(students.begin(), students.end(), [&]( Student& s) {
                return s.id == id;
            });

            if (it != students.end()) {
                // 学生已存在，直接更新姓名
                it->name = name;
            } else {
                // 学生不存在，创建新的学生结构体并添加到学生列表中
                student.id = id;
                student.name = name;
                students.push_back(student);
            }
        }
        else if(lines.size()==3)
        {
            string id=lines[0];
            string course=lines[1];
            double score=stod(lines[2]);

            // 检查学生列表中是否已经存在该学生的基本信息
            auto it = find_if(students.begin(), students.end(), [&]( Student& s) {
                return s.id == id;
            });

            if (it != students.end()) {
                // 学生已存在，直接更新成绩信息
                it->scores[course] = score;
            } else {
                // 学生不存在，创建新的学生结构体并添加到学生列表中
                student.id = id;
                student.scores[course] = score;
                students.push_back(student);
            }

            if(find(courseNames.begin(), courseNames.end(), course) == courseNames.end())
            {
                courseNames.push_back(course);
            }
        }
    }
    //按学号排序
    sort(students.begin(),students.end(),cmpID);
    sort(courseNames.begin(), courseNames.end());
    /*
    输出结果
    1.表头
    2.学生信息
    3.平均分汇总
    */
   cout<<"student id, name,";
   for(auto&course : courseNames)
   {
    cout<<course<<",";
   }
   cout<<" average"<<endl;

   for(auto& student:students)
   {
    cout<<student.id<<","<<student.name<<", ";
    for(auto& course:courseNames)
    {
        if(student.scores.count(course)>0)
        {
            cout<<fixed<<setprecision(1)<<student.scores.at(course)<<", ";
        }
        else
        {
            cout<<", ";
        }
        
    }
    student.CalAvgScore(student.scores);
    cout<<fixed<<setprecision(1)<<student.avgScore<<endl;
   }

   cout<<", , ";
   for(auto&course:courseNames)
   {
    double courseAvg=0;
    int cnt=0;
    for(auto&student:students)
    {
        if(student.scores.count(course)>0)
        {
            courseAvg+=student.scores.at(course);
            cnt++;
        }
    }
    if(cnt>0)
    {
        courseAvg/=cnt;
        avgSum+=courseAvg;
        cout<<fixed<<setprecision(1)<<courseAvg<<", ";
    }
    else
    {
        cout<<", ";
    }
   }
   cout << (avgSum / courseNames.size());
   cout<<endl;
    return 0;
}