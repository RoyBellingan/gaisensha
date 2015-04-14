#ifndef IMPRESSION_H
#define IMPRESSION_H


class impression{
public:
    impression();
    bool check_group(unsigned int g);
    bool check_banner(unsigned int g);
    ~impression();
};

#endif // IMPRESSION_H
