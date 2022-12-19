/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rokupin <rokupin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 00:14:39 by rokupin           #+#    #+#             */
/*   Updated: 2022/12/07 00:15:00 by rokupin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include "Zombie.hpp"

int main(){
//	Task requirement
	const int kHordeSize = 10;
	Zombie *horde = Zombie::zombieHorde(kHordeSize, "Andy");

	for (int i = 0; i < kHordeSize; ++i) {
		horde[i].announce();
	}
//	convinient way to deallocate [] array
	delete[] horde;
//	How it actually works
	std::vector<Zombie> real_horde = Zombie::ZombieHordeAsItShouldBe(kHordeSize, "Andy");
//	Iterating by values
	for (Zombie z  : real_horde) {
		z.announce();
	}
//	Iterating by const reference
	for (const auto& z  : real_horde) {
		z.announce();
	}
	return 0;
}
