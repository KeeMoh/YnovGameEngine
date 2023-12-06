#include <iostream>
#include "YnovGameEngine/Application.h"
#include "YnovGameEngine/AComponent.h"
#include "YnovGameEngine/CircleComponent.h"
#include "YnovGameEngine/SpriteRenderer.h"
#include "YnovGameEngine/Camera.h"
#include "YnovGameEngine/ResourceManager.h"
#include <SFML/Graphics.hpp>
#include <YnovGameEngine/AEntity.h>
#include "CameraRotation.h"
#include "Controller.h"
#include <Box2D/box2d.h>
#include "YnovGameEngine/Rigidbody.h"
#include "YnovGameEngine/BoxCollider.h"


int main()
{

    // WIP, sorry master

    //YnovGameEngine::ResourceManager rm;
    //rm.FindPath();

    
    // ---------- Create Systeme Application ----------
    YnovGameEngine::Application app;
    //YnovGameEngine::Physics physics;
    // ---------- Create First Entity ----------
    YnovGameEngine::Entity* spriteEntity = app.CreateEntity();

    // ---------- Sprite Component ----------
    YnovGameEngine::SpriteRenderer* sprite = spriteEntity->AddComponent<YnovGameEngine::SpriteRenderer>();
    sprite->CreateSprite(app.GetResourceManager()->GetPathFromId("1"));
    YnovGameEngine::Rigidbody* rigidbody = spriteEntity->AddComponent<YnovGameEngine::Rigidbody>();
    rigidbody->SetBodyType(b2_dynamicBody);
    YnovGameEngine::BoxCollider* boxCollider = spriteEntity->AddComponent<YnovGameEngine::BoxCollider>();

    //Set Box Collider
    boxCollider->SetColliderDensity(0);
    boxCollider->SetColliderFriction(1);
    boxCollider->SetSize(sprite->GetSize().x, sprite->GetSize().y);
    boxCollider->CreateFixture(rigidbody->GetBody());
    spriteEntity->setPosition(100, 100);

    //Make spriteEntity playable with Controller
    Controller* controller = spriteEntity->AddComponent<Controller>();


    // ---------- Create Second Entity ----------
    YnovGameEngine::Entity* groundEntity = app.CreateEntity();

    YnovGameEngine::SpriteRenderer* sprite2 = groundEntity->AddComponent<YnovGameEngine::SpriteRenderer>();
    sprite2->CreateSprite(app.GetResourceManager()->GetPathFromId("0"));
    YnovGameEngine::Rigidbody* rigidbody2 = groundEntity->AddComponent<YnovGameEngine::Rigidbody>();
    rigidbody->SetBodyType(b2_dynamicBody);
    YnovGameEngine::BoxCollider* boxCollider2 = groundEntity->AddComponent<YnovGameEngine::BoxCollider>();

    //Set Box Collider
    boxCollider2->SetColliderDensity(1);
    boxCollider2->SetColliderFriction(1);
    boxCollider2->SetSize(sprite2->GetSize().x, sprite2->GetSize().y);
    boxCollider2->CreateFixture(rigidbody2->GetBody());
    groundEntity->setPosition(100, -200);


    // ---------- Camera Entity ----------
    YnovGameEngine::Entity* cameraEntity = app.CreateEntity();
    // ---------- Camera Component ----------
    YnovGameEngine::Camera* camera = cameraEntity->AddComponent<YnovGameEngine::Camera>();

    cameraEntity->setPosition(100, 100);

    camera->SetCenter(sf::Vector2f(40, 40));
    camera->SetZoom(1);
    camera->SetRotation(0);

    /*b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(0.0f, -10.0f);*/

    //CameraRotation* cameraRotation = cameraEntity->AddComponent<CameraRotation>();
    
    //camera->SetRotation(65); 
    //camera->SetCenter(entity1->getPosition() + sf::Vector2f(5, 5));
    app.Loop();

    // ---------- The end ----------


    //sf::View view2(sf::Vector2f(350, 300), sf::Vector2f(300, 200));

    //YnovGameEngine::Application* app = YnovGameEngine::Application::getInstance();
    //app.getInstance();
    /*sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Blue);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;*/
}