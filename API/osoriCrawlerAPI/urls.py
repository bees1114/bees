from django.conf.urls import url
from rest_framework.urlpatterns import format_suffix_patterns
from osoriCrawlerAPI import views

urlpatterns = [
    url(r'^users/$', views.UserList.as_view()),
    url(r'^user/$', views.UserDetail.as_view()),
    url(r'^crawlers/$', views.CrawlerList.as_view()),
    url(r'^crawler/$', views.CrawlerDetail.as_view()),
    url(r'^subscriptions/$', views.SubscriptionList.as_view()),
    url(r'^subscriptions/item/$', views.SubscriptionDetail.as_view()),
    url(r'^tokens/$', views.PushTokenList.as_view()),
    url(r'^tokens/(?P<id>[a-z0-9]+)/$', views.PushTokenDetail.as_view()),
    url(r'^email_auth/(?P<auth>.+)/$', views.Auth.email_auth),
    url(r'^send_temp_password/(?P<user_id>.+)/$', views.ForgetPassword.as_view()),
    url(r'^password_change/$', views.ChangePassword.as_view()),
    url(r'^subscribers_pushtoken/$', views.SubscriberPushToken().as_view())
]

urlpatterns = format_suffix_patterns(urlpatterns)