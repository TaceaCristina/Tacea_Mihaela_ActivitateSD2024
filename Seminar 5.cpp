#include "pch.h"
#include "Seminar_5.h"
#if __has_include("Seminar_5.g.cpp")
#include "Seminar_5.g.cpp"
#endif

using namespace winrt;
using namespace Windows::UI::Xaml;

namespace winrt::SDDCrisTacea::implementation
{
    int32_t Seminar_5::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void Seminar_5::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }

    void Seminar_5::ClickHandler(IInspectable const&, RoutedEventArgs const&)
    {
        Button().Content(box_value(L"Clicked"));
    }
}
