#include "ShipShooterComponent.h"

#include "GameObject.h"
#include "PhysicComponent.h"

void ShipShooterComponent::Shoot()
{
	auto timeSinceLastShoot = (double)m_Timer.GetTickSinceStart() / 1000;
	if(timeSinceLastShoot <= m_ShootDelay)
		return;
	m_Timer.Stop();
	m_Timer.Start();

	GameObject* bullet = &m_BulletPool->GetObject().GetGameObject();
	bullet->GetTransform().SetPosition(m_Owner->GetTransform().GetPosition());
	bullet->GetTransform().SetForward(m_Owner->GetTransform().GetForward());
	PhysicComponent* physic;
	bullet->GetComponent(&physic);
	physic->SetVelocity(m_Owner->GetTransform().GetForward() * m_BulletSpeed);
}
