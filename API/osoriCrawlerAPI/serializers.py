from django.forms import widgets
from rest_framework import serializers
from osoriCrawlerAPI.models import UserProfile

class UserProfileSerializer(serializers.ModelSerializer):
    class Meta:
        model = UserProfile
        fields = ('id', 'name', 'password', 'email', 'created', 'last_login')