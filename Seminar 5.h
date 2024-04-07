#pragma once

#include "Seminar_5.g.h"

namespace winrt::SDDCrisTacea::implementation
{
    struct Seminar_5 : Seminar_5T<Seminar_5>
    {
        Seminar_5() 
        {
            // Xaml objects should not call InitializeComponent during construction.
            // See https://github.com/microsoft/cppwinrt/tree/master/nuget#initializecomponent
        }

        int32_t MyProperty();
        void MyProperty(int32_t value);

        void ClickHandler(Windows::Foundation::IInspectable const& sender, Windows::UI::Xaml::RoutedEventArgs const& args);
    };
}

namespace winrt::SDDCrisTacea::factory_implementation
{
    struct Seminar_5 : Seminar_5T<Seminar_5, implementation::Seminar_5>
    {
    };
}
