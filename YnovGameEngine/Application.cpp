#include "Application.h"

YnovGameEngine::Application* YnovGameEngine::Application::_instance = nullptr;

YnovGameEngine::Application::Application()
{
    if (!_instance) {
        _instance = this;
    }
    _Init();
}

void YnovGameEngine::Application::_Init()
{
    //Init config file
    _resourceManager = new ResourceManager();

    long screenWidth = 1600;//sf::VideoMode::getDesktopMode().width;
    long screenHeight = 900;//sf::VideoMode::getDesktopMode().height;

    _InitWindow(screenWidth, screenHeight);
    
    _physics = new Physics;
    //_resourceManager.FindPath("");
}

void YnovGameEngine::Application::_InitWindow(long horizontal, long vertical)
{
    //std::cout << "Horizontal>" << horizontal << " - Vertical>" << vertical;
    _window.create(sf::VideoMode(horizontal, vertical), "Let's Play!");

}

YnovGameEngine::Application *YnovGameEngine::Application::GetInstance()
{
    if (!_instance) {
        _instance = new Application();
    }
    return _instance;
}

YnovGameEngine::Entity* YnovGameEngine::Application::GetEntityFromComponent(AComponent* comp)
{
    //Boucle sur entities
    //Boucle sur components liés.
    //Si component lié = comp alors on a trouvé l'entité reliée à ce composant.
    //A remplacer ? lors de l'attachement des components pour les stocker dans un tableau
    for (Entity* entity : _entities) {
        std::vector<AComponent*> components = entity->GetComponents();
        for (AComponent* component : components) {
            std::cout << entity->GetID() + " - " + component->GetId() << std::endl;
            if (component == comp) {
                return entity;
            }
        }
    }
    return nullptr;
}

void YnovGameEngine::Application::Loop()
{
    //call function for drawing sprite component
    //working with shape for the moment
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    //créer une entité avec un component circle sprite 
    //Boucle pour récupérer toutes mes entitées

    sf::Clock clock;
    std::cout << " - LOOP - " << std::endl;
    while (_window.isOpen())
    {
        float deltaTime = clock.restart().asSeconds();
        sf::Event event;
        while (_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                _window.close();
        }

        Update(deltaTime);
        Draw();
    }
}

void YnovGameEngine::Application::Update(float deltaTime)
{

    for (Entity* entity : _entities) {
        entity->Update(deltaTime);
    }
    //Call Update for physic world
    _physics->Update(deltaTime);
    //Call function LateUpdate on each entity
    for (Entity* entity : _entities) {
        entity->LateUpdate(deltaTime);
    }
}

void YnovGameEngine::Application::Draw()
{
    _window.clear();
    //SetView();
    for (Entity* entity : _entities) {
        //draw our entities
        _window.draw(*entity);
    }
    //Get current view
    /*sf::View currentView = _window.getView();*/

    _window.display();
}

void YnovGameEngine::Application::SetView()
{
    //// on crée une vue
    //sf::View view(sf::FloatRect(0, 0, 1000, 600));

    //// on l'active
    //_window.setView(view);
}

YnovGameEngine::Physics* YnovGameEngine::Application::GetWorldPhysics()
{
    return _physics;
}

YnovGameEngine::ResourceManager* YnovGameEngine::Application::GetResourceManager()
{
    return _resourceManager;
}

YnovGameEngine::Entity* YnovGameEngine::Application::CreateEntity()
{
    Entity* entity = new Entity();
    _entities.push_back(entity);

    return entity;
}

sf::RenderWindow* YnovGameEngine::Application::GetWindow()
{
    return &_window;
}

std::vector<YnovGameEngine::Entity*> YnovGameEngine::Application::GetEntities()
{
    return _entities;
}

std::string YnovGameEngine::Application::GetInputKeyboard()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
    {
        return "Z";
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
    {
        return "Q";
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        return "S";
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
        return "D";
    }
    return nullptr;
}

