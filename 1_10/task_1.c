#include <stdio.h>
#define N 50000

typedef struct DateTime_s
{
    int year, month, day;
    int hours, minutes, seconds;
} DateTime;


DateTime MinDate(const DateTime *arr, int cnt)
{
    DateTime res = arr[0];
    int sec, days;
    int secMin = res.hours*3600 + res.minutes*60 + res.seconds;
    int daysMin = res.year*365 + res.month*31 + res.day;
    for(int i = 1; i < cnt; i++)
    {
        sec = arr[i].hours*3600 + arr[i].minutes*60 + arr[i].seconds;
        days = arr[i].year*365 + arr[i].month*31 + arr[i].day;
        if (days == daysMin)
        {
            if (sec < secMin)
            {
                res = arr[i];
                daysMin = days;
                secMin = sec;
            }
        }
        else
        {
            if (days < daysMin)
            {
                res = arr[i];
                daysMin = days;
                secMin = sec;
            }
        }
    }
    return res;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    DateTime dates[N];
    DateTime minD;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d%d%d%d%d%d", &dates[i].year, &dates[i].month, &dates[i].day, &dates[i].hours, &dates[i].minutes, &dates[i].seconds);
    }
    minD = MinDate(dates, n);
    printf("%d %d %d %d %d %d", minD.year, minD.month, minD.day, minD.hours, minD.minutes, minD.seconds);
    return 0;
}

