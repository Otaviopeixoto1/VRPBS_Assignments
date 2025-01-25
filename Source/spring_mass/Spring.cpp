// Fill out your copyright notice in the Description page of Project Settings.

#include "Spring.h"
#include "spring_mass.h"

Spring::Spring(MassPoint* m1, MassPoint* m2, float length) :
m_m1(m1), m_m2(m2), 
m_spring_length_init(length),
m_stiffness(0.1),
m_damper(0.001)
{
}

Spring::~Spring()
{
}


void 
Spring::Tick()
{	
	//Vector pointing from mass 1 to mass 2:
	FVector r12 = (m_m2->m_currPos - m_m1->m_currPos);
	float spring_length = r12.Length();
	r12.Normalize();

	//Force applied on mass 1 in the direction of mass 2
	FVector f12 = m_stiffness * (spring_length - m_spring_length_init) * r12         //Elastic force
				- m_damper * ((m_m1->m_velocity - m_m2->m_velocity).Dot(r12)) * r12; //Damping force

	m_m1->addForce(f12);
	m_m2->addForce(-f12);
}
