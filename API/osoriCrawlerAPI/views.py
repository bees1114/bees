from rest_framework import status
from rest_framework.views import APIView
from rest_framework.response import Response
from django.http import Http404
from osoriCrawlerAPI.models import UserProfile
from osoriCrawlerAPI.serializers import UserProfileSerializer


class UserList(APIView):
    def get(self, request, format=None):
        users=UserProfile.objects.all()
        if users.count() == 0:
            return Response('No')
        userSerializer = UserProfileSerializer(users, many=True)
        return Response(userSerializer.data)

    def post(self, request, format=None):
        userSerializer = UserProfileSerializer(data = request.data)
        if userSerializer.is_valid():
            userSerializer.save()
            return Response(userSerializer.data, status=status.HTTP_201_CREATED)

        return Response(userSerializer.errors, status=status.HTTP_400_BAD_REQUEST)

class UserDetail(APIView):
    def get_object(self, id):
        try:
            return UserProfile.objects.get(id=id)
        except UserProfile.DoesNotExist:
            return False

    def get(self, request, id, format=None):
        uid = request.GET.get("id")
        upwd = request.GET.get("password")

        if uid:
            user = UserProfile.objects.filter(id=uid)
            if user.count() > 0:
                if user[0].password == upwd:
                    result = uid + 'Login!'
                else:
                    result = uid + ' fail to login'
            else:
                result = uid + ' does not exist'
        else:
            result = uid + ' does not exist'
        return Response(result)

    def put(self, request, id, format=None):
        user = self.get_object(id)
        userSerializer = UserProfileSerializer(user, data=request.data)
        if userSerializer.is_valid():
            userSerializer.save()
            return Response(userSerializer.data)
        return Response(userSerializer.errors, status=status.HTTP_400_BAD_REQUEST)

    def delete(self, request, id, format=None):
        user=self.get_object(id)
        if user == False:
            return Response("invalid user")
        user.delete()
        return Response(id + " deleted")


'''
def signup(request):
    if request.method == "POST":
        body_unicode = request.body.decode('utf-8')
        body = json.loads(body_unicode)
        uid = body['id']
        upwd = body['password']

        if UserProfile.objects.filter(id=uid).count() >0 :
            result = uid + ' already exist'
        else:
            user = UserProfile(id=uid, password=upwd)
            user.save()
            result = uid + 'create'

    elif request.method == "GET":
        uid = request.GET.get("id")
        upwd = request.GET.get("password")

        if uid:
            user = UserProfile.objects.filter(id=uid)
            if user.count() > 0:
                if user[0].password == upwd:
                    result = uid + 'Login!'
                else:
                    result = uid + ' fail to login'
            else:
                result = uid + ' does not exist'

        else:
            result = uid + ' does not exist'
    #update
    elif request.method == 'UPDATE':

    #delete
    elif request.method == 'DELETE':
        uid = request.GET.get("id")
        upwd = request.GET.get("password")
        if uid:
            user = UserProfile.objects.filter(id=uid)
            if user.count() > 0:
                if user[0].password == upwd:
                    user[0].delete()
                    result = uid + ' Profile Deleted'
                else:
                    result = 'Password error'
            else:
                result = uid + ' does not exist'
    else:
        result = "This request method doesn`t exist"
    return render(request, 'registration/signup.html', {'result': result})
'''