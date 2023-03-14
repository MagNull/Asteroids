#include "DamageDealerComponent.h"

void DamageDealerComponent::Damage(IDamageable* damageable)
{
	damageable->TakeDamage(m_Damage);
}
