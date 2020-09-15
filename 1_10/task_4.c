#include <stdio.h>
#include <string.h>
#define N 1000

typedef struct Label_s
{
    char name[16];
    int age;
} Label;

typedef struct NameStats_s
{
    int cntTotal;
    int cntLong;
} NameStats;

typedef struct AgeStats_s
{
    int cntTotal;
    int cntAdults;
    int cntKids;

} AgeStats;

void CalcStats(const Label *arr, int cnt, NameStats *oNames, AgeStats *oAges)
{
    oNames->cntTotal = cnt;
    oAges->cntTotal = cnt;
    for(int i = 0; i < cnt; i++)
    {
        if (strlen(arr[i].name) > 10)
            oNames->cntLong++;
        if (arr[i].age >= 18)
            oAges->cntAdults++;
        else if (arr[i].age < 14)
            oAges->cntKids++;
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n;
    Label labs[N];
    NameStats names;
    AgeStats ages;
    char trash[3];
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%s%d%s", labs[i].name, &labs[i].age, trash);
    CalcStats(labs, n, &names, &ages);
    printf("names: total = %d\n", names.cntTotal);
    printf("names: long = %d\n", names.cntLong);
    printf("ages: total = %d\n", ages.cntTotal);
    printf("ages: adult = %d\n", ages.cntAdults);
    printf("ages: kid = %d\n", ages.cntKids);
    return 0;
}

