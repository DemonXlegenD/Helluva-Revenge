#pragma once
#include "Components/Entity.h"

class EnemyB : public Entity {
public:
    EnemyB();
    void Update(const float& _delta) override;
    void ChasePlayer(const float& _delta);

    void InitializeAnimations();

private:
    float speed;
    bool isChasing;
    Maths::Vector2f lastKnownPlayerPosition;

    Animation* idleAnimation;
    Animation* chaseAnimation;
    Animation* biteAnimation;
    Animation* deathAnimation;
};