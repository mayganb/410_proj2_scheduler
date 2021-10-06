/*
 * Stats.cpp
 *
 *  Created on: Sep 10, 2019
 *      Author: keith
 */

//TODO fill in content
#include "../includes/stats.h"
#include <vector>
#include <iostream>

using namespace std;

Stats::Stats(std::vector<PCB> &finished_vector){
	vec = &finished_vector;
	av_wait_time = 0.0;
	av_turnaround_time = 0.0;
	av_response_time = 0.0;
}

	//loops thru vec, prints 1 line for each process using the following format
	//Process 1 Required CPU time:2  arrived:0 started:0 finished:2
	//if there are 10 processes in vector, should print 10 lines
void Stats::showAllProcessInfo(){
	for(int i = 0; i < vec->size();i++){
		cout<<"CPU time:" << vec->at(i).required_cpu_time << " arrived:" << vec->at(i).arrival_time << " started:" << vec->at(i).start_time << " finished:" << vec->at(i).finish_time << endl;
	}
}

	//after a process is placed in the ready_q, how long does
	//it take before its placed on the processor?
	//response_time per process = start_time - arrival_time
	//this funtion returns the average over all processes
float Stats::get_av_response_time(){
	float sum = 0;
	if(vec->size() == 0){
		return 0.0;
	}
	for(int i = 0; i < vec->size();i++){
		sum += (vec->at(i).start_time) - (vec->at(i).arrival_time);
	}
	return (float)sum/ (float)(vec->size());
}

	//after a process is placed in the ready_q, how long does
	//it take to complete?
	//turnaround time per process = finish_time - arrival_time
	//this funtion returns the average over all processes
float Stats::get_av_turnaround_time(){
	float sum = 0;
	if(vec->size() == 0){
		return 0.0;
	}
	for(int i = 0; i < vec->size();i++){
		sum += (vec->at(i).finish_time) - (vec->at(i).arrival_time);
	}
	return (float)sum/ (float)(vec->size());
}

	//after a process is placed in the ready_q, how much time does it
	//spend waiting for processor time?
	//wait time per process = finish_time - arrival_time-required_CPU_time
	//this funtion returns the average over all processes
float Stats::get_av_wait_time(){
	float sum = 0;
	if(vec->size() == 0){
		return 0.0;
	}
	for(int i = 0; i < vec->size();i++){
		sum += (vec->at(i).finish_time) - (vec->at(i).arrival_time) - (vec->at(i).required_cpu_time);
	}
	return (float)sum/ (float)(vec->size());

}

void Stats::calcStats(){
	av_wait_time = get_av_wait_time();
	av_turnaround_time = get_av_turnaround_time();
	av_response_time = get_av_response_time();
}
