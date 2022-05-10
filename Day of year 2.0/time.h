#pragma once

int day_of_the_year(int year, int month, int days);

int is_leapyear(int year);

int get_days_for_month(int year, int month);

int exists_date(int year, int month, int days);

void input_date(int *year, int *month, int *days);

int day_of_the_week(int y, int m, int d);

int week_of_the_year(int year, int days_of_year, int days_of_week);
