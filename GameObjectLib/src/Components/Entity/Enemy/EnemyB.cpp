#include "Components/Entity/Enemy/EnemyB.h"
#include "Managers/SceneManager.h"
#include "Components/RigidBody2D.h"
#include "Components/Animation.h"
#include "Managers/AssetManager.h"

EnemyB::EnemyB() : Entity() {
    speed = 5.f;  // Vitesse de base de l'ennemi
    isChasing = false;
}

void EnemyB::Update(const float& _delta) {
    Entity::Update(_delta);

    auto player = SceneManager::GetActiveGameScene()->GetPlayer();
    if (player) {
        Maths::Vector2f enemyPosition = this->GetOwner()->GetPosition();
        Maths::Vector2f playerPosition = player->GetPosition();

        float distanceToPlayer = enemyPosition.Distance(playerPosition);

        if (distanceToPlayer < 500) {  // 500 est la portée de détection du joueur
            isChasing = true;
            lastKnownPlayerPosition = playerPosition;
        }

        if (isChasing) {
            if (!chaseAnimation->GetIsPlaying()) {
                idleAnimation->Stop();
                chaseAnimation->Play();
            }
            ChasePlayer(_delta);
        }
        else {
            if (!idleAnimation->GetIsPlaying()) {
                chaseAnimation->Stop();
                idleAnimation->Play();
            }
        }
    }
}

void EnemyB::ChasePlayer(const float& _delta) {
    Maths::Vector2f enemyPosition = this->GetOwner()->GetPosition();
    Maths::Vector2f direction = lastKnownPlayerPosition - enemyPosition;
    direction.Normalize();  // Normalise le vecteur direction
    this->GetOwner()->GetComponent<RigidBody2D>()->AddForces(direction * _delta * speed);

    // Une fois que l'ennemi a dépassé la dernière position connue du joueur, il arrête de poursuivre
    if (enemyPosition.Distance(lastKnownPlayerPosition) < 10.f) {
        isChasing = false;
    }
}
