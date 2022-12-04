

#include <set>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
// add or remove necessary headers as you please
#include "schedwork.h"

using namespace std;

// a constant that can be used to indicate an INVALID 
// worker ID if that is useful to your implementation.
// Feel free to not use or delete.
static const Worker_T INVALID_ID = (unsigned int)-1;


// Add prototypes for any helper functions here


// Add your implementation of schedule() and other helper functions here
bool f(int day, int worker, size_t rem,
    const size_t dailyNeed,
    vector<int> maxShifts,
    const AvailabilityMatrix& avail,
    DailySchedule& sched, DailySchedule& sched2)
{
    
    if (day == 0  && rem == 0){
      sched2=sched;
      return true;
    }
    if (day ==0 && worker < 0) return false;
    if (worker<0 || rem==0){
        if (rem!=0) return false;
        return f(day-1, avail[0].size()-1, dailyNeed,dailyNeed, maxShifts, avail, sched, sched2);
    }
    bool ans = f(day, worker-1, rem, dailyNeed, maxShifts, avail, sched, sched2);
    if (avail[day][worker] && maxShifts[worker]>0) {
      maxShifts[worker]--;
      sched[day][rem-1] = worker;
      ans |= f(day, worker-1, rem-1, dailyNeed, maxShifts, avail, sched, sched2);
      maxShifts[worker]++;
    }
    return ans;
}
bool schedule(
    const AvailabilityMatrix& avail,
    const size_t dailyNeed,
    const size_t maxShifts,
    DailySchedule& sched
)
{
    if(avail.size() == 0U){
        return false;
    }
    sched.clear();
    sched.resize(avail.size(), vector<Worker_T>(dailyNeed));
    // Add your code below
    vector<int> v;
    for (auto i = 0; i < avail[0].size(); i++) v.push_back(maxShifts);
    DailySchedule temp = sched;
    return f(avail.size()-1, avail[0].size()-1, dailyNeed, dailyNeed, v, avail, temp, sched);



}

