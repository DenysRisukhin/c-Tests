//
//  Scheme.h
//  Test2019
//
//  Created by Risukhin Denys on 1/12/24.
//  Copyright © 2024 DenysRisukhin. All rights reserved.
//

#ifndef Scheme_h
#define Scheme_h

//В цілому MVC, MVP та MVVM майже те саме. Є View у всіх, є модель даних (M) і головне це є клас який відповідає за логіку - це Controller або Presenter або View Model. Реально те саме але по різному називається. В iOS відрізняється саме реалізація - який компонент від якого залежить та як відбувається зв’язок між компонентами. На приклад в MVVM зазвичай вʼюха підписується на оновлення ViewModel через Observer.

//Here's a simplified diagram illustrating the common theme across
//  Model-View-Controller (MVC)
//  Model-View-Presenter (MVP)
//  Model-View-ViewModel (MVVM)
//  Entity-Component-System (ECS)

+---------------------+          +---------------------+          +---------------------+          +---------------------+
|       Model         |          |       Model         |          |       Model         |          |    Entity           |
+---------------------+          +---------------------+          +---------------------+          +---------------------+
| - Manages Data      |    ----> | - Manages Data      |    ----> | - Manages Data      |          | - Components        |
| - Business Logic    |    <---- | - Business Logic    |    <---- | - Business Logic    |          | - Behaviors         |
| - Notifies Changes  |          | - Notifies Changes  |          | - Notifies Changes  |          | - Data (optional)   |
+---------------------+          +---------------------+          +---------------------+          +---------------------+
          ^                              ^                              ^
          |                              |                              |
+---------------------+          +---------------------+          +---------------------+
|       View          |          |       View          |          |       View          |
+---------------------+          +---------------------+          +---------------------+
| - Displays Data     |          | - Displays Data     |          | - Displays Data     |
| - User Interface    |          | - User Interface    |          | - User Interface    |
| - Listens for Input |          | - Listens for Input |          | - Listens for Input |
| - Updates on Change |    ----> | - Updates on Change |    ----> | - Updates on Change |
| - Sends Commands    |    <---- | - Sends Commands    |    <---- | - Sends Commands    |
+---------------------+          +---------------------+          +---------------------+
          ^                              ^                              ^
          |                              |                              |
+---------------------+          +---------------------+          +---------------------+
|     Controller      |          |     Presenter       |          |     ViewModel       |          |     System          |
+---------------------+          +---------------------+          +---------------------+          +---------------------+
| - Handles User Input|          | - Handles User Input|          | - Handles User Input|          | - Processes Entities|
| - Interacts with M,V|    <---- | - Interacts with M,V|    <---- | - Interacts with M,V|          | - Applies Logic     |
| - Updates the Model |    ----> | - Updates the Model |    ----> | - Updates the Model |          | - Notifies Changes  |
+---------------------+          +---------------------+          +---------------------+          +---------------------+

Model:
    Manages data, business logic, and notifies changes.
    Acts as the central point for data and logic.
View:
    Displays data, user interface elements.
    Listens for user input, updates on changes, and sends commands.
Controller (MVC):
    Handles user input, interacts with the model and view, updates the model.
Presenter (MVP):
    Handles user input, interacts with the model and view, updates the model.
    Mediates between the model and view.
ViewModel (MVVM):
    Handles user input, interacts with the model and view, updates the model.
    Acts as an abstraction of the view with data-binding to the model.
Entity (ECS):
    Represents a game object.
    Consists of components (data) and may have behaviors.
Component (ECS):
    Represents the data or attributes of an entity.
    May include behaviors.
System (ECS):
    Processes entities based on their components.
    Applies logic and notifies changes.

#endif /* Scheme_h */
