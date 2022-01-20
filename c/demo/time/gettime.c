#include <stdio.h>
#include <time.h>

static struct tm* get_now_time() {
    time_t now_time;
    now_time = time(NULL);
    printf("[DEBUG] %d\n", now_time);
    return gmtime(&now_time);
}

int main(int argc, const char *argv[]) {
    struct tm *now_time;
    now_time = get_now_time();
    printf("[DEBUG] year is %d\n", now_time->tm_year+1900);
    printf("[DEBUG] month is %d\n", now_time->tm_mon+1);
    printf("[DEBUG] day is %d\n", now_time->tm_mday);
    printf("[DEBUG] hour is %d\n", now_time->tm_hour);
    printf("[DEBUG] minute is %d\n", now_time->tm_min);
    printf("[DEBUG] second is %d\n", now_time->tm_sec);
    printf("[DEBUG] zone is %s\n", now_time->tm_zone);
    printf("[DEBUG] zone is %s\n", now_time->tm_isdst);
    return 0;
}
