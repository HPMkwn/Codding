#include <bits/stdc++.h>
using namespace std;

struct StringMeeting {
    string start;
    string end;

    StringMeeting(string s,string e): start(s),end(e){};
    StringMeeting(): start(),end(){};
};


int duration(StringMeeting a){
     
    vector <string> tokens1;
    vector <string> tokens2;
     
    stringstream check1(a.start);
    stringstream check2(a.end);
     
    string intermediate;
    while(getline(check1, intermediate, ':'))
    {
        tokens1.push_back(intermediate);
    }

    while(getline(check2, intermediate, ':'))
    {
        tokens2.push_back(intermediate);
    }

    cout<<tokens1[0]<<" "<<tokens1[1]<<"\n";
    cout<<tokens2[0]<<" "<<tokens2[1]<<"\n"; 

    int astart = stoi(tokens1[0]);
    int aend = stoi(tokens1[1]);
    int bstart = stoi(tokens2[0]);
    int bend = stoi(tokens2[1]);

    int difference =0;
    difference += (bstart-astart)*60;
    difference += (bend - aend);
    return difference;
}

bool isTimeGreater(string first,string second){
     
    vector <string> tokens1;
    vector <string> tokens2;
     
    stringstream check1(first);
    stringstream check2(second);
     
    string intermediate;
    while(getline(check1, intermediate, ':'))
    {
        tokens1.push_back(intermediate);
    }

    while(getline(check2, intermediate, ':'))
    {
        tokens2.push_back(intermediate);
    }

    cout<<tokens1[0]<<" "<<tokens1[1]<<"\n";
    cout<<tokens2[0]<<" "<<tokens2[1]<<"\n"; 

    int astart = stoi(tokens1[0]);
    int aend = stoi(tokens1[1]);
    int bstart = stoi(tokens2[0]);
    int bend = stoi(tokens2[1]);

    if(astart != bstart)astart < bstart;
    return aend < bend;
}

vector<StringMeeting> findFreeTime(vector<StringMeeting> calendar, StringMeeting dailyBounds,int meetingDuration){

    if(calendar.empty())return vector<StringMeeting>{};
    

    vector<StringMeeting> ret;
    if(calendar[0].start > dailyBounds.start && duration(StringMeeting(dailyBounds.start,calendar[0].start))>=meetingDuration){
        StringMeeting meeting(dailyBounds.start,calendar[0].start);
        ret.push_back(meeting);
    }

    for(int i=0;i<calendar.size()-1;i++){

        StringMeeting meeting(calendar[i].end,calendar[i+1].start);
        if(meeting.start != meeting.end && duration(meeting)>=meetingDuration)
            ret.push_back(meeting);
    }

    if(calendar[calendar.size()-1].end < dailyBounds.end && duration(StringMeeting(calendar[calendar.size()-1].end,dailyBounds.end))>=meetingDuration){
        StringMeeting meeting(calendar[calendar.size()-1].end,dailyBounds.end);
        ret.push_back(meeting);
    }
    
    for(int i=0;i<ret.size();i++){
        cout<<"("<<ret[i].start<<":"<<ret[i].end<<"), ";
    }
    cout<<"\n";
    return ret;
}
void recursiveCheck(vector<StringMeeting> &freeTime1,vector<StringMeeting> &freeTime2,int i,int j,set<StringMeeting> &ret,int meetingDuration){
    int m=freeTime1.size(),n=freeTime2.size();
    if(i>=m || j>=n)return;

    StringMeeting a = freeTime1[i];
        StringMeeting b = freeTime2[j];
				cout<<"i: "<<i<<", "<<"j: "<<j<<"\n";
    
    if(isTimeGreater(a.end,b.start)){cout<<"isGreater("<<a.end<<", "<<b.start<<")"<<isTimeGreater(a.end,b.start)<<"\n";return recursiveCheck(freeTime1,freeTime2,i+1,j,ret,meetingDuration);}
    else if(isTimeGreater(b.end,a.start)){cout<<"isGreater("<<b.end<<", "<<a.start <<")"<<isTimeGreater(b.end,a.start)<<"\n";return recursiveCheck(freeTime1,freeTime2,i,j+1,ret,meetingDuration);}
    else{
        StringMeeting tempMeeting;

        if(a.start < b.start)tempMeeting.start = b.start;
        else tempMeeting.start = a.start;

        if(a.end > b.end)tempMeeting.end = b.end;
        else tempMeeting.end = a.end;

        if(duration(tempMeeting)>= meetingDuration){
            ret.insert(tempMeeting);
        }
                
        recursiveCheck(freeTime1,freeTime2,i+1,j,ret,meetingDuration);
        recursiveCheck(freeTime1,freeTime2,i,j+1,ret,meetingDuration);
    }
}
vector<StringMeeting> calendarMatching(vector<StringMeeting> calendar1,StringMeeting dailyBounds1,vector<StringMeeting> calendar2,StringMeeting dailyBounds2,int meetingDuration) {
    
    set<StringMeeting> ret;
    vector<StringMeeting> freeTime1= findFreeTime(calendar1,dailyBounds1,meetingDuration);
    vector<StringMeeting> freeTime2= findFreeTime(calendar2,dailyBounds2,meetingDuration);

    recursiveCheck(freeTime1,freeTime2,0,0,ret,meetingDuration);
		    

    vector<StringMeeting> returnArray;
	for(auto x : ret){
		returnArray.push_back(x);
	}
    return returnArray;
}



int main() { 
    StringMeeting meeting("18:45","20:30");

    cout<<"difference : "<<duration(meeting)<<"\n";
    return 0; }