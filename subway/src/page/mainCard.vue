<template>
  <section>
    <div class="content">
      <div class="main">
        <img src="http://aicixi.img-cn-shanghai.aliyuncs.com/20180108012351844_35.png" />
        <div v-show="hasCard" id="cardScan">
          <img :src="scan" id="scan"/>
          <span id="scanTip">刷码乘车 延时扣款</span>
          <div id="getCard" @click="myCards()">
            <span>杭州通支付宝交通卡</span>
            <img src="http://aicixi.img-cn-shanghai.aliyuncs.com/20180108015116758_90.png"/>
          </div>
        </div>
        <div v-show="!hasCard" id="noCard">
          <img src="http://aicixi.img-cn-shanghai.aliyuncs.com/20180108020629633_30.png" />
          <span>您还没有领卡</span>
          <button @click = "getCard()">立即领卡</button>
        </div>
      </div>
    </div>
    <Dialog @close="myCards()" @select="changSelect" :control="mycard" :cardList="cardList"/>
  </section>
</template>

<script>
import Dialog from '@/components/cardDialog'
export default {
  name: 'mainCard',
  data () {
    return {
      hasCard: true,
      mycard: false,
      scan: 'http://221.180.255.85:8089/group1/M00/00/03/rBSEOVorchiAZbP6AAAF7ZyVClc707.png',
      cardList: [
        {name: '杭州市公交卡', isSelect: false, id: 1, logo: 'http://aicixi.img-cn-shanghai.aliyuncs.com/20180109042230981_34.jpg', support: true},
        {name: '杭州市公交卡', isSelect: false, id: 2, logo: 'http://aicixi.img-cn-shanghai.aliyuncs.com/20180109042230981_34.jpg', support: false},
        {name: '杭州市公交卡', isSelect: true, id: 3, logo: 'http://aicixi.img-cn-shanghai.aliyuncs.com/20180109042230981_34.jpg', support: false},
        {name: '杭州市公交卡', isSelect: false, id: 4, logo: 'http://aicixi.img-cn-shanghai.aliyuncs.com/20180109042230981_34.jpg', support: false}
      ]
    }
  },
  components: {Dialog},
  methods: {
    getCard () {
      let scope = this
      scope.$router.push({path: '/cardList'})
    },
    myCards () {
      this.mycard = !this.mycard
    },
    changSelect (id) {
      let scope = this
      scope.cardList = scope.cardList.map((item) => {
        if (item.id === id) {
          item.isSelect = true
        } else {
          if (item.isSelect === true) {
            item.isSelect = false
          }
        }
        return item
      })
      scope.myCards()
    }
  },
  // 页面挂载
  mounted () {
  },
  created () {
    window.vv = this
    // let scope = this
    document.title = '电子公交卡'
  }
}
</script>

<!-- Add "scoped" attribute to limit CSS to this component only -->
<style scoped lang='scss'>
@import '../common/style/variable.scss';
  .content {
    @include fill-all;
    margin: 0;
    padding: 1rem;
    background-color: #f6f8f7;

    .main {
      width: 100%;
      height: 100%;
      background-color: #fff;
      border-radius:3%;
      img {
        width: 100%;
      }

      #cardScan {
        width: 100%;
        height: 60%;
        text-align: center;
        #scan {
          width:75%;
          margin: 0 auto;
          margin-top: 5%;
          margin-bottom:5%;
          display: block;
        }
        #scanTip {
          font-size: 1.8rem;
          color: #666666;
          display: block;
        }
        #getCard {
          display: inline-block;
          margin-top: 10%;
          height: 1.8rem;
          position: releative;
          img {
            width: 1rem;
            positive: absolute;
            top: 50%;
            transform: translateY(-12%);
          }
          span {
            line-height: 1.8rem;
            font-size: 1.8rem;
            color: #666666;
          }
        }
      }

      #noCard  {
        width: 100%;
        height: 60%;
        text-align: center;
        img {
          width: 25%;
          display: block;
          margin: 0 auto;
          margin-top:30%;
          margin-bottom: 8%;
        }
        span {
          color: #333333;
          font-size: 2rem;
        }
        button {
          width: 90%;
          height: 7vh;
          border-radius: 0.5rem;
          display: block;
          margin: 0 auto;
          margin-top: 23%;
          font-size: 2rem;
          color: #fff;
          background-color: #1592ff;
        }
      }
    }
  }
</style>
