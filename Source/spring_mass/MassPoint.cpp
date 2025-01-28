// Fill out your copyright notice in the Description page of Project Settings.

#include "MassPoint.h"
#include "spring_mass.h"


MassPoint::MassPoint(uint32 vertex_id, bool movable, FVector pos) :
m_vertex_id(vertex_id),
m_currPos(pos),
m_prevPos(pos),
is_first_iteration(true),
m_force(FVector::ZeroVector),
m_velocity(FVector::ZeroVector),
m_movable(movable),
m_mass(0.00005)
{
}

void
MassPoint::updateGravity()
{
	m_force -= 9.8f * m_mass * FVector::UpVector;
}

void 
MassPoint::updateCurPos(float deltaT)
{
	if (m_movable)
	{
		//Euler:
		//m_velocity += m_force / m_mass * deltaT;
		//m_currPos += m_velocity * deltaT;
		
		//Verlet
		FVector newPrevPos = m_currPos;
		if (is_first_iteration)
		{
			m_currPos += m_velocity * deltaT + 0.5f * m_force / m_mass * deltaT * deltaT;
			is_first_iteration = false;
		}
		else
		{
			m_currPos = 2 * m_currPos - m_prevPos + m_force / m_mass * deltaT * deltaT;
		}
		
		m_prevPos = newPrevPos;
		m_velocity = (m_currPos - m_prevPos) / deltaT;
	}
	m_force = FVector::ZeroVector;
}

void
MassPoint::addForce(FVector f)
{
	if (m_movable)
	{
		m_force += f;
	}
}

MassPoint::~MassPoint()
{
}
