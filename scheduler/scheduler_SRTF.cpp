/*
 * SchedulerSRTF.cpp
 *
 *  Created on: Sep 10, 2019
 *      Author: keith
 *
 *      implements shortest remaining time first scheduling algorithm
 *     pre-emptive
 */

//TODO fill in content
#include "../includes/scheduler_SRTF.h"
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

	//override base class behaviour if necessary, otherwise call it
bool Scheduler_SRTF::time_to_switch_processes(int tick_count, PCB &p){
	sort();
	if( ready_q->front().remaining_cpu_time > 0 && ready_q->front().remaining_cpu_time < p.remaining_cpu_time && ready_q->front().process_number != p.process_number ){
		return true;
	}
	return p.remaining_cpu_time <= 0;
}
bool My_Function(PCB &i, PCB &j){
	return i.remaining_cpu_time < j.remaining_cpu_time;
}

	//SRTF-preemptive - sort ready_q by remaining_cpu_time whenever add(PCB p) or time_to_switch_processes is called
void Scheduler_SRTF::sort(){
	vector<PCB> vec;
	while(!ready_q->empty()){
		vec.push_back(ready_q->front());
		ready_q->pop();
	}

	std::sort(vec.begin(), vec.end(), My_Function);

	for(int i = 0; i < vec.size();i++){
		ready_q->push(vec.at(i));
	}

}

