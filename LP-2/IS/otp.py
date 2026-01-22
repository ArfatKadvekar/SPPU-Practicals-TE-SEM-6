import random

otp = random.randint(100000, 999999)

print("Your OTP is:", otp)  

user_otp = int(input("Enter OTP: "))

if user_otp == otp:
    print("OTP Verified Successfully")
else:
    print("Invalid OTP")
