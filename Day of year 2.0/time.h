#pragma once

struct year {
    int day;
    int month;
    int year;
};

int day_of_the_year(struct year day_of_year);

int is_leapyear(int year);

int get_days_for_month(struct year day_of_month);

int exists_date(struct year exist);

void input_date(struct year *input);

int day_of_the_week(struct year week);

int week_of_the_year(int year, int days_of_year, int days_of_week);
