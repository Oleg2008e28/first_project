/*
 * main.h
 *
 * Created: 03.01.2021 22:28:31
 *  Author: User-HP
 */ 


#ifndef MAIN_H_
#define MAIN_H_

#ifdef F_CPU
#undef F_CPU
# warning "F_CPU defined earlier!!!"
#else
#define F_CPU 12000000UL
#endif /*F_CPU*/

#endif /* MAIN_H_ */