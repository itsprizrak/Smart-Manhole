from django.shortcuts import render, redirect
from django.http import HttpResponse
from django.contrib.auth import logout
from django.contrib.auth.decorators import login_required
import serial

  
# homepage view
def WelcomeView(request):
	return render(request,'welcome.html')



# dashboard view with auth permission
@login_required
def DashBoard(request):
	message = 1
	list1 = []
	try:
		ard = serial.Serial('com12', 9600)
		message = 0
		print("connected")
		try:
			count = 0
			while count < 3:
				val = float(ard.readline())
				list1.append(val)
				count = count+1
			accelerometer = list1[0]
			gas = list1[1]
			rain = list1[2]
			list1.pop()
			list1.pop()
			list1.pop()
		except:
			temperature = 0
			rain = 0
			gas = 0

		context = {'accelerometer':accelerometer,'rain':rain,'gas':gas,'message':message}
	 
		return render(request, 'dashboard.html', context)
	except:
	
		return HttpResponse("Please check your connection")

	
# user logout view
@login_required
def LogoutView(request):
	logout(request)
	return redirect('manhole:homepage')