import Vue from 'vue'
import Router from 'vue-router'
// import HelloWorld from '@/components/HelloWorld'
import mainCard from '@/page/mainCard'
import cardList from '@/page/cardList'
import cityList from '@/page/cityList'
import cardDialog from '@/components/cardDialog'
import authorize from '@/page/authorize'

Vue.use(Router)

export default new Router({
  routes: [
    {
      path: '/test',
      name: 'cardDialog',
      component: cardDialog
    },
    {
      path: '/',
      name: 'mainCard',
      component: mainCard
    },
    {
      path: '/cardList',
      name: 'cardList',
      component: cardList
    },
    {
      path: '/cityList',
      name: 'cityList',
      component: cityList
    },
    {
      path: '/authorize',
      name: 'authorize',
      component: authorize
    }
  ]
})
