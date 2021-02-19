#include<bits/stdc++.h>
using namespace std;

class Workshop
{
    int start_time;
    int duration;
    int end_time;
public:
    void set_start_time(int start_time)
    {
        this->start_time = start_time;
    }
    void set_duration(int duration)
    {
        this->duration = duration;
    }
    void set_end_time()
    {
        this->end_time = start_time + duration;
    }
    int get_start_time()
    {
        return start_time;
    }
    int get_end_time()
    {
        return end_time;
    }
    int get_duration()
    {
        return duration;
    }
};

class Available_Workshops
{
    int n;  // the number of workshops the student signed up for
    Workshop *workshops;
public:
    explicit Available_Workshops(int n) : n(n)
    {
        workshops = new Workshop[n];
    }
    ~Available_Workshops()
    {
        delete[] workshops;
    }

    /**
     * Initializes the available workshops that could be attended
     * @param start_times an array with n times that mark the start of the
     *                    workshop
     * @param durations   an array with n times that mark the duration of the workshop
     * @param n           the number of available workshops
     */
    void initialize_workshops(int start_times[], int durations[], int n)
    {
        for (int i = 0; i < n; ++i)
        {
            workshops[i].set_start_time(start_times[i]);
            workshops[i].set_duration(durations[i]);
            workshops[i].set_end_time();
        }
    }

    /**
     * Uses the algorithm for interval scheduling
     * (https://en.wikipedia.org/wiki/Interval_scheduling) to find the maximum
     * workshops that can be attended
     * @return the maximum number of workshops that can be attended
     */
    int interval_scheduling()
    {
        // sort by end_time using a lambda expression
        std::sort(workshops, workshops + n, [](Workshop &a, Workshop &b) {
            return a.get_end_time() < b.get_end_time();
        });

        int total_workshops = 1;    // the total number of workshops that can be attended
        int last_end_time = workshops[0].get_end_time();    // the end_time of the latest workshop that can be attended
        for (int i = 1; i < n; ++i)
        {
            if (workshops[i].get_start_time() >= last_end_time)
            {
                total_workshops++;
                last_end_time = workshops[i].get_end_time();
            }
        }

        return total_workshops;
    }
};

Available_Workshops *initialize(int start_times[], int durations[], int n)
{
    Available_Workshops *avail_work = new Available_Workshops(n);
    avail_work->initialize_workshops(start_times, durations, n);
    return avail_work;
}

int CalculateMaxWorkshops(Available_Workshops *ptr)
{
    return ptr->interval_scheduling();
}

int main()
{
    int n;  // number of workshops
    std::cin >> n;
    // create arrays of unknown size n
    int* start_time = new int[n];
    int* duration = new int[n];

    for (int i = 0; i < n; i++)
        std::cin >> start_time[i];
    for (int i = 0; i < n; i++)
        std::cin >> duration[i];

    Available_Workshops *ptr;
    ptr = initialize(start_time, duration, n);
    std::cout << CalculateMaxWorkshops(ptr) << std::endl;

    return 0;
}
