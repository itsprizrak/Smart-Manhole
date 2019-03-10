from django.urls import path
from django.contrib.auth.views import LoginView
from .views import DashBoard, WelcomeView, LogoutView
app_name = 'manhole'

urlpatterns = [
	path('', WelcomeView, name='homepage'),
	path('dashboard/', DashBoard, name='dashboard'),
	path('login/', LoginView.as_view(template_name='login.html'), name='login'),
	path('logout/', LogoutView, name='logout'),


]